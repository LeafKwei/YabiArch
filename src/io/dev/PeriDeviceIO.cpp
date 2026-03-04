#include "def/err.hpp"
#include "def/port.hpp"
#include "def/ioid.hpp"
#include "io/dev/PeriDeviceIO.hpp"
#include "io/dev/term/TermIO.hpp"
YABI_BEGIN

PeriDeviceIO::PeriDeviceIO(){
    registerDevices();
}

int PeriDeviceIO::ioid() const noexcept{
    return IOID_DEV;
}

qword_t PeriDeviceIO::in(memaddr_t port, iosize_t n){
    try{
        auto pair = devices_.find(port2key(port));
        if(pair == devices_.end()){
            throw YabiExcept(ERRIOPORT, "No such device attached.");
        }

        return pair -> second -> in(port, n);
    }
    catch(YabiExcept &e){
        throw;
    }
    catch(std::exception &e){
        throw YabiExcept(ERRIODEV, e.what());
    }
}

void PeriDeviceIO::out(memaddr_t port, qword_t data, iosize_t n){
    try{
        auto pair = devices_.find(port2key(port));
        if(pair == devices_.end()){
            throw YabiExcept(ERRIOPORT, "No such device attached.");
        }

        pair -> second -> out(port, data, n);
    }
    catch(YabiExcept &e){
        throw;
    }
    catch(std::exception &e){
        throw YabiExcept(ERRIODEV, e.what());
    }
}

void PeriDeviceIO::attachDevice(RandomIO *device, memaddr_t lowport, memaddr_t highport){
    /* 提前检查每个key对应位置是否已有设备 */
    if(checkOverride(lowport, highport)){
        throw YabiExcept(ERRRANGE, "Attaching device overrides a another device.");
    }

    /* 在每个key的位置挂载设备 */
    for(; lowport <= highport; lowport += PORT_ALLOC_SIZE){
        auto key = port2key(lowport);
        DevicePtr ptr(device);
        devices_.insert({key, ptr});
    }
}

bool PeriDeviceIO::detachDevice(memaddr_t lowport, memaddr_t highport){
    for(; lowport <= highport; lowport += PORT_ALLOC_SIZE){
        auto key = port2key(lowport);
        return devices_.erase(key) > 0;
    }

    return false;
}

bool PeriDeviceIO::checkOverride(memaddr_t lowport, memaddr_t highport) const{
    for(; lowport <= highport; lowport += PORT_ALLOC_SIZE){
        if(devices_.find(port2key(lowport)) != devices_.end()){
            return true;
        }
    }

    return false;
}

void PeriDeviceIO::registerDevices(){
    /* 将终端IO设备挂载到端口范围0~31 */
    attachDevice(
        new TermIO(),
        PORT_TERM_IN,
        PORT_TERM_IN + PORT_ALLOC_SIZE - 1
    );
}

YABI_END