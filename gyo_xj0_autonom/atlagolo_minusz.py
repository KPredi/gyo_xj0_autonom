import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32, Float64

class Atlagolo(Node):
    def __init__(self):
        super().__init__('atlagolo_m')
        self.current_batch = []
        self.count = 0

        self.subscription = self.create_subscription(
            Int32,
            'szamok_minusz',
            self.number_callback,
            10
        )

        self.publisher = self.create_publisher(Float64, 'atlag_minusz', 10)

    def number_callback(self, msg):
        self.current_batch.append(msg.data)

        if len(self.current_batch) >= 10:
            avg = sum(self.current_batch) / len(self.current_batch)
            self.count += 1
            self.get_logger().info(f'Batch {self.count} average: {avg:.2f}')

            avg_msg = Float64()
            avg_msg.data = avg
            self.publisher.publish(avg_msg)

            self.current_batch.clear()


def main(args=None):
    rclpy.init(args=args)
    node = Atlagolo()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
