#include <chrono>
#include <memory>
#include <random>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

using namespace std::chrono_literals;

class NumberGenerator : public rclcpp::Node
{
public:
    NumberGenerator()
    : Node("szam_generator"), mt(rd()), dist(0, 500)
    {
        publisher_ = this->create_publisher<std_msgs::msg::Int32>("szamok_plusz", 10);
        timer_ = this->create_wall_timer(
            100ms, std::bind(&NumberGenerator::publish_number, this));
    }

private:
    void publish_number()
    {
        auto message = std_msgs::msg::Int32();
        message.data = dist(mt);  // 0–100 véletlen szám
        publisher_->publish(message);
        RCLCPP_INFO(this->get_logger(), "Generated: %d", message.data);
    }

    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    std::random_device rd;
    std::mt19937 mt;
    std::uniform_int_distribution<int> dist;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<NumberGenerator>());
    rclcpp::shutdown();
    return 0;
}

