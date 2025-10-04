from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # Pluszos generátor
        Node(
            package='gyo_xj0_autonom',
            executable='generator',
            name='generator',
            output='screen'
        ),

        # Mínuszos generátor
        Node(
            package='gyo_xj0_autonom',
            executable='generator_minusz',
            name='generator_minusz',
            output='screen'
        ),

        # Pluszos átlagoló
        Node(
            package='gyo_xj0_autonom',
            executable='atlagolo',
            name='atlagolo',
            output='screen'
        ),

        # Mínuszos átlagoló
        Node(
            package='gyo_xj0_autonom',
            executable='atlagolo_minusz',
            name='atlagolo_minusz',
            output='screen'
        ),

        # Átlagok összeadó
        Node(
            package='gyo_xj0_autonom',
            executable='sum_averages',
            name='sum_averages',
            output='screen'
        ),
    ])
