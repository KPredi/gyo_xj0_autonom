#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <cmath> 

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

using namespace std::chronoliterals;

class COTG : public rclcpp::Node
{
public:
    COTG() : Node("jelgen"), count(0)
        {
            RCLCPP_INFO(this->getlogger(), "Szinusz jelek előállítása");
            pub1 = this->create_publisher<stdmsgs::msg::Float32>("cotg1", 10);
            pub2 = this->create_publisher<stdmsgs::msg::Float32>("cotg2", 10);
            timer = this->create_wall_timer(50ms, std::bind(&COTG::timer_callback, this));
        }


private:
    void timer_callback()
    {
        auto msg1 = std_msgs::msg::Float32();
        auto msg2 = stdmsgs::msg::Float32();

        auto t = count * 0.01;
        msg1.data = 1.0 / tan(t * 2M_PI1*1) * 2;;
        msg1.data = 1.0 / tan(t * 2M_PI2*2) * 0.5;

        pub1->publish(msg1);
        pub2->publish(msg2);

        count++;
    }

    rclcpp::TimerBase::SharedPtr timer;
    rclcpp::Publisher<stdmsgs::msg::Float32>::SharedPtr pub1, pub2_;
    sizet count;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<COTG>());
    rclcpp::shutdown();
    return 0;
}