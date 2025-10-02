#include <vector>
#include <memory>
#include <numeric>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

class Atlagolo : public rclcpp::Node
{
public:
    Atlagolo()
    : Node("atlagolo"), count_(0)
    {
        subscription_ = this->create_subscription<std_msgs::msg::Int32>(
            "numbers", 10, std::bind(&Atlagolo::number_callback, this, std::placeholders::_1));
    }

private:
    void number_callback(const std_msgs::msg::Int32::SharedPtr msg)
    {
        current_batch_.push_back(msg->data);

        // Ha összegyűlt 100 szám
        if (current_batch_.size() >= 100)
        {
            double avg = std::accumulate(current_batch_.begin(), current_batch_.end(), 0.0) / current_batch_.size();
            RCLCPP_INFO(this->get_logger(), "Batch %d average: %.2f", count_+1, avg);

            current_batch_.clear();
            count_++;

            // Ha már 10 batch megvan, leáll a node
            if (count_ >= 10)
            {
                rclcpp::shutdown();
            }
        }
    }

    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscription_;
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
