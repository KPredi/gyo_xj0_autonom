#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"

class SumAverages : public rclcpp::Node
{
public:
    SumAverages() : Node("atlag_ossz"), avg1_(0.0), avg2_(0.0) 
    {
        publisher_ = this->create_publisher<std_msgs::msg::Float64>("atlag_ossz", 10);

        sub1_ = this->create_subscription<std_msgs::msg::Float64>(
            "atlag_plusz", 10, std::bind(&SumAverages::callback1, this, std::placeholders::_1));

        sub2_ = this->create_subscription<std_msgs::msg::Float64>(
            "atlag_minusz", 10, std::bind(&SumAverages::callback2, this, std::placeholders::_1));
    }

private:
    void callback1(const std_msgs::msg::Float64::SharedPtr msg)
    {
        avg1_ = msg->data;
        publish_sum();
    }

    void callback2(const std_msgs::msg::Float64::SharedPtr msg)
    {
        avg2_ = msg->data;
        publish_sum();
    }

    void publish_sum()
    {
        auto msg = std_msgs::msg::Float64();
        msg.data = avg1_ + avg2_;
        publisher_->publish(msg);
        RCLCPP_INFO(this->get_logger(), "Sum: %.2f", msg.data);
    }

    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher_;
    rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr sub1_;
    rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr sub2_;
    double avg1_, avg2_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SumAverages>());
    rclcpp::shutdown();
    return 0;
}
