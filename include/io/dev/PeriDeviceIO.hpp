#ifndef YABI_PERIDEVICEIO_HPP
#define YABI_PERIDEVICEIO_HPP

#include <unordered_map>
#include <memory>
#include "io/RandomIO.hpp"
YABI_BEGIN

class PeriDeviceIO : public RandomIO{
public:
    PeriDeviceIO();
    int ioid() const noexcept override;
    void attachDevice(RandomIO *device, memaddr_t lowport, memaddr_t highport);   //挂载设备到指定的端口范围
    bool detachDevice(memaddr_t lowport, memaddr_t highport);                                  //卸载指定端口范围内的设备，返回设备是否卸载成功
	qword_t in(memaddr_t port, iosize_t n) override;
    void out(memaddr_t port, qword_t data, iosize_t n) override;

private:
    using DevicePtr = std::shared_ptr<RandomIO>;
    using DeviceHub = std::unordered_map<memaddr_t, DevicePtr>;

private:
    DeviceHub devices_;

private:
    bool checkOverride(memaddr_t lowport, memaddr_t highport) const;
    void registerDevices();
};

YABI_END
#endif