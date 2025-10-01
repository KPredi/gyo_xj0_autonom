from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='gyo_xj0_autonom',
            executable='generator',
        ),

        Node(
            package='gyo_xj0_autonom',
            executable='eredmeny',
        ),
    ])