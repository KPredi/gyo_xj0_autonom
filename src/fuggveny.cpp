#include <vector>
#include <memory>
#include <numeric>
#include <algorithm>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"

class Fuggveny : public rclcpp::Node
{
public:
    Fuggveny()
    : Node("fuggveny"), count_(0)
    {
        subscription_ = this->create_subscription<std_msgs::msg::Float64>(
            "averages", 10, std::bind(&Fuggveny::average_callback, this, std::placeholders::_1));
    }

private:
    void average_callback(const std_msgs::msg::Float64::SharedPtr msg)
    {
        averages_.push_back(msg->data);
        RCLCPP_INFO(this->get_logger(), "Received average: %.2f", msg->data);

        count_++;
        if (count_ >= 10)
        {
            // Kész a “függvény”: számolunk egyszerű statisztikát
            double overall_avg = std::accumulate(averages_.begin(), averages_.end(), 0.0) / averages_.size();
            double max_val = *std::max_element(averages_.begin(), averages_.end());
            double min_val = *std::min_element(averages_.begin(), averages_.end());

            RCLCPP_INFO(this->get_logger(), "Function result -> Average: %.2f, Max: %.2f, Min: %.2f",
                        overall_avg, max_val, min_val);

            rclcpp::shutdown();
        }
    }

    rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr subscription_;
    std::vector<double> averages_;
    int count_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Fuggveny>());
    rclcpp::shutdown();
    return 0;
}
