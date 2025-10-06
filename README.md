# `kis_beadando` package
ROS 2 C++ package.  [![Static Badge](https://img.shields.io/badge/ROS_2-Humble-34aec5)](https://docs.ros.org/en/humble/)
## Packages and build

It is assumed that the workspace is `~/ros2_ws/`.

### Clone the packages
``` r
cd ~/ros2_ws/src
```
``` r
git clone https://github.com/KPredi/kis_beadando
```

### Build ROS 2 packages
``` r
cd ~/ros2_ws
```
``` r
colcon build --packages-select kis_beadando --symlink-install
```

<details>
<summary> Don't forget to source before ROS commands.</summary>

``` bash
source ~/ros2_ws/install/setup.bash
```
</details>

``` r
ros2 run kis_beadando generator
ros2 run kis_beadando atlagolo
ros2 run kis_beadando generator_minusz
ros2 run kis_beadando atlagolo_minusz
ros2 run kis_beadando atlagolo_ossz
```
### szimuláció indítása 
``` r
ros2 run rqt_plot rqt_plot
(/numbers/data)
```
