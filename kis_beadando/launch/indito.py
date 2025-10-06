from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(package='kis_beadando', executable='atlagolo', name='atlagolo', output='screen'),
        Node(package='kis_beadando', executable='generator',    name='generator',    output='screen'),
        Node(package='kis_beadando', executable='atlagolo_ossz',  name='atlagolo_ossz',  output='screen'),
        Node(package='kis_beadando', executable='atlagolo_minusz', name='atlagolo_minusz', output='screen'),
        Node(package='kis_beadando', executable='generator_minusz',    name='generator_minusz',    output='screen'),
    ])