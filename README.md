# `gyo_xj0_autonom` package

## Kis beadandó

### Feladat leírása
Működés:

A Publisher node-ok:

"szam_generator" 0 és 500 közötti véletlen számokat küld a "szamok_plusz" topicra.

"szam_generator_m" –500 és 0 közötti véletlen számokat küld a "szamok_minusz" topicra.

A Subscriber node-ok:

"atlagolo" a "szamok_plusz" topicról érkező értékeket 10-esével átlagolja, majd az eredményt az "atlag_plusz" topicra küldi.

"atlagolo_m" a "szamok_minusz" topicról érkező értékeket dolgozza fel ugyanígy, és az "atlag_minusz" topicra küldi az átlagot.

"atlag_ossz" feliratkozik az "atlag_plusz" és "atlag_minusz" topicokra, majd összeadja a két átlagot, és az eredményt az "atlag_ossz" topicra publikálja.

### Indítás:
``` r
cd ~/ros2_ws/src
```
``` r
git clone https://github.com/KPredi/gyo_xj0_autonom
```
``` r
cd ~/ros2_ws
```
``` r
colcon build --packages-select gyo_xj0_autonom --symlink-install
```
``` r
source ~/ros2_ws/install/setup.bash
```
``` r
ros2 launch gyo_xj0_autonom indito.py
```
``` r
ros2 run rqt_plot rqt_plot
/szamok_plusz/data
/szamok_minusz/data
/atlag_plusz/data
/atlag_minusz/data
/atlag_ossz/data

```
