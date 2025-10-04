from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='gyo_xj0_autonom',
            executable='generator',
            name='generator',
            output='screen'
        ),
        Node(
            package='gyo_xj0_autonom',
            executable='generator_minusz',
            name='generator_minusz',
            output='screen'
        ),
        Node(
            package='gyo_xj0_autonom',
            executable='atlagolo',
            name='atlagolo',
            output='screen'
        ),
        Node(
            package='gyo_xj0_autonom',
            executable='atlagolo_minusz',
            name='atlagolo_minusz',
            output='screen'
        ),
        Node(
            package='gyo_xj0_autonom',
            executable='atlagolo_ossz',
            name='atlagolo_ossz',
            output='screen'
        ),
    ])
