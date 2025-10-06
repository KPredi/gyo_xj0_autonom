import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64

class SumAverages(Node):
    def __init__(self):
        super().__init__('atlag_ossz')
        self.avg1 = 0.0
        self.avg2 = 0.0

        self.publisher = self.create_publisher(Float64, 'atlag_ossz', 10)

        self.sub1 = self.create_subscription(
            Float64,
            'atlag_plusz',
            self.callback1,
            10
        )

        self.sub2 = self.create_subscription(
            Float64,
            'atlag_minusz',
            self.callback2,
            10
        )

    def callback1(self, msg):
        self.avg1 = msg.data
        self.publish_sum()

    def callback2(self, msg):
        self.avg2 = msg.data
        self.publish_sum()

    def publish_sum(self):
        msg = Float64()
        msg.data = self.avg1 + self.avg2
        self.publisher.publish(msg)
        self.get_logger().info(f'Sum: {msg.data:.2f}')


def main(args=None):
    rclpy.init(args=args)
    node = SumAverages()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
