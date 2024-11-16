## Introduction
This project serves as a template of dual core application for Grove Vision AI Module v2 (WE2)



[![License: GPL v3](https://img.shields.io/badge/License-GPL_v3-blue.svg)](https://github.com/teamprof/we2-sdk/blob/main/LICENSE)

<a href="https://www.buymeacoffee.com/teamprof" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Buy Me A Coffee" style="height: 28px !important;width: 108px !important;" ></a>

---
## Hardware
The following components are required for this project:
1. [Grove Vision AI Module V2](https://wiki.seeedstudio.com/grove_vision_ai_v2/)
2. [OV5647 camera module](https://www.seeedstudio.com/OV5647-69-1-FOV-Camera-module-for-Raspberry-Pi-3B-4B-p-5484.html)

---
## Build firmware on the Grove Vision AI Module v2 (WE2)
### Clone repo
```
git clone https://github.com/teamprof/we2-sdk
cd we2-sdk
```

### Build CM55 big core app
```
cd EPII_CM55M_APP_S
make clean
make -f makefile-we2-gui
```

### Build CM55 little core app
```
cd EPII_CM55S_APP_S
make clean
make -f makefile-we2-gui
```

### Generate image file 
```
cd ../we2_image_gen_local/
cp ../EPII_CM55M_APP_S/obj_epii_evb_icv30_bdv10/gnu_epii_evb_WLCSP65/EPII_CM55M_gnu_epii_evb_WLCSP65_s.elf input_case3_secboot/
cp ../EPII_CM55S_APP_S/obj_epii_evb_icv30_bdv10/gnu_epii_evb_WLCSP65/EPII_CM55S_gnu_epii_evb_WLCSP65_s.elf input_case3_secboot/

./we2_local_image_gen project_case3_blp_wlcsp.json

Output firmware image: ./output_case3_sec_wlcsp/output.img
```

---

## Flash firmware on the Grove Vision AI Module v2 (WE2)
Please refer to README-org.md about the steps to flash firmware on Grove Vision AI Module v2 


---

## Current issue
### Only big core runs normally, little core doesn't.
[![we2-run](/doc/image/we2-run.png)](https://github.com/teamprof/we2-sdk/blob/main/doc/image/cover-image.png)
---


## LED
- WE2 LED1 (yellow): 

---

## Code explanation


---

## Demo


---
### Debug

---
### Troubleshooting
If you get compilation errors, more often than not, you may need to install a newer version of the coralmicro.

Sometimes, the project will only work if you update the board core to the latest version because I am using newly added functions.

---
### Issues
Submit issues to: [github-we2-sdk issues](https://github.com/teamprof/we2-sdk/issues) 

---
### TO DO
1. Search for bug and improvement.
---

### Contributions and Thanks
Many thanks to the following authors who have developed great software and libraries.
1. [Seeed Studio Grove Vision AI Module V2](https://wiki.seeedstudio.com/grove_vision_ai_v2/)
2. [Seeed Studio OV5647-62 FOV Camera Module](https://www.seeedstudio.com/OV5647-69-1-FOV-Camera-module-for-Raspberry-Pi-3B-4B-p-5484.html)

#### Many thanks for everyone for bug reporting, new feature suggesting, testing and contributing to the development of this project.
---

### Contributing
If you want to contribute to this project:
- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library
---

### License
- The project is licensed under GNU GENERAL PUBLIC LICENSE Version 3
---

### Copyright
- Copyright 2024 teamprof.net@gmail.com. All rights reserved.



