import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32
import random

class NumberGenerator(Node):
    def __init__(self):
        super().__init__('szam_generator_m')
        self.publisher = self.create_publisher(Int32, 'szamok_minusz', 10)
        self.timer = self.create_timer(0.1, self.publish_number)  # 100 ms
        random.seed()

    def publish_number(self):
        msg = Int32()
        msg.data = random.randint(-500, 0)
        self.publisher.publish(msg)
        self.get_logger().info(f'Generated: {msg.data}')


def main(args=None):
    rclpy.init(args=args)
    node = NumberGenerator()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
