#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"
#include <cmath>
#include <chrono>

using namespace std::chrono_literals;

class Generator : public rclcpp::Node
{
public:
    Generator() : Node("generator"), count(0)
    {
        pub1 = this->create_publisher<std_msgs::msg::Float32>("cotg1", 10);
        pub2 = this->create_publisher<std_msgs::msg::Float32>("cotg2", 10);

        timer = this->create_wall_timer(
            50ms, std::bind(&Generator::timer_callback, this));
    }

private:
    void timer_callback()
    {
        auto msg1 = std_msgs::msg::Float32();
        auto msg2 = std_msgs::msg::Float32();

        double t = count * 0.01;

        msg1.data = 1.0 / tan(t * 2 * M_PI * 1) * 2.0;
        msg2.data = 1.0 / tan(t * 2 * M_PI * 2) * 0.5;

        pub1->publish(msg1);
        pub2->publish(msg2);

        RCLCPP_INFO(this->get_logger(), "Publishing: cotg1=%.3f cotg2=%.3f", msg1.data, msg2.data);

        count++;
    }

    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr pub1;
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr pub2;
    rclcpp::TimerBase::SharedPtr timer;
    size_t count;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Generator>());
    rclcpp::shutdown();
    return 0;
}
