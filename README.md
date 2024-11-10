# qmk-keymaps

Note to myself:

```
sudo apt install -y python3-pip pipx
pipx install qmk
cd ~/git
git clone -b wireless_playground --single-branch \ 
  git@github.com:Keychron/qmk_firmware.git
export PATH=$PATH:/home/claus/.local/bin
cd qmk_firmware
qmk setup
qmk hello

ln -s ~/git/qmk-keymaps/keychron_k8_pro \
  keyboards/keychron/k8_pro/iso/rgb/keymaps/cloonix
ln -s ~/git/qmk-keymaps/keychron_v1_max \
  keyboards/keychron/v1_max/iso_encoder/keymaps/cloonix
  
make keychron/k8_pro/iso/rgb:cloonix
make keychron/v1_max/iso_encoder:cloonix
```
