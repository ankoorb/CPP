# Container environment 

This provides a Dockerfile which can be used to build a Docker image locally and run a container for the environment setup of this project. It is an Ubuntu environemt with an LXDE desktop, based on an [existing Docker image](https://hub.docker.com/r/dorowu/ubuntu-desktop-lxde-vnc/).

## Setup

* Clone the project or your own fork:

```
git clone https://github.com/udacity/CppND-System-Monitor-Project-Updated.git
```

* Build the Docker image:

```bash
docker build -t environment-monitor .
```

* Run the Docker container, by mounting the project's directory from your host to the container:

```bash
docker run -p 6080:80 -v /Users/ankoor/Desktop/Programming/UdacityC++/SystemMonitor/CppND-System-Monitor-Project-Updated:/root/project/CppND-System-Monitor-Project-Updated environment-monitor
```

* Open `http://localhost:6080/` on your browser to see the Ubuntu Desktop.

* Open the terminal in Ubuntu to build and execute the project:

```bash
cd /root/project/CppND-System-Monitor-Project-Updated
mkdir build
cd build
cmake ..
make
./monitor
```