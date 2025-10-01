#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

class Eredmeny : public rclcpp::Node
{
public:
    Eredmeny() : Node("eredmeny"), val1(0.0), val2(0.0)
    {
        pub = this->create_publisher<std_msgs::msg::Float32>("eredmeny", 10);

        sub1 = this->create_subscription<std_msgs::msg::Float32>(
            "cotg1", 10,
            std::bind(&Eredmeny::callback1, this, std::placeholders::_1));

        sub2 = this->create_subscription<std_msgs::msg::Float32>(
            "cotg2", 10,
            std::bind(&Eredmeny::callback2, this, std::placeholders::_1));
    }

private:
    void callback1(const std_msgs::msg::Float32::SharedPtr msg)
    {
        val1 = msg->data;
        publish_sum();
    }

    void callback2(const std_msgs::msg::Float32::SharedPtr msg)
    {
        val2 = msg->data;
        publish_sum();
    }

    void publish_sum()
    {
        auto sum_msg = std_msgs::msg::Float32();
        sum_msg.data = val1 + val2;
        pub->publish(sum_msg);

        RCLCPP_INFO(this->get_logger(), "Sum: %.3f", sum_msg.data);
    }

    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr pub;
    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr sub1;
    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr sub2;

    float val1, val2;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Eredmeny>());
    rclcpp::shutdown();
    return 0;
}
