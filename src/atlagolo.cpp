#include <vector>
#include <memory>
#include <numeric>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include "std_msgs/msg/float64.hpp"

class Atlagolo : public rclcpp::Node
{
public:
    Atlagolo()
    : Node("atlagolo"), count_(0)
    {
        subscription_ = this->create_subscription<std_msgs::msg::Int32>(
            "szamok_plusz", 10, std::bind(&Atlagolo::number_callback, this, std::placeholders::_1));

        publisher_ = this->create_publisher<std_msgs::msg::Float64>("atlag_plusz", 10);
    }

private:
    void number_callback(const std_msgs::msg::Int32::SharedPtr msg)
    {
        current_batch_.push_back(msg->data);

        if (current_batch_.size() >= 100)
        {
            double avg = std::accumulate(current_batch_.begin(), current_batch_.end(), 0.0) / current_batch_.size();
            RCLCPP_INFO(this->get_logger(), "Batch %d average: %.2f", count_+1, avg);

            // Publikáljuk az átlagot a fuggveny node-nak
            auto avg_msg = std_msgs::msg::Float64();
            avg_msg.data = avg;
            publisher_->publish(avg_msg);

            current_batch_.clear();
        }
    }

    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscription_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher_;
    std::vector<int> current_batch_;
    int count_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Atlagolo>());
    rclcpp::shutdown();
    return 0;
}
