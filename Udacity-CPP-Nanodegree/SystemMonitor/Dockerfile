FROM dorowu/ubuntu-desktop-lxde-vnc:focal

WORKDIR /root/project

# Install dependencies
# See: https://github.com/cpp-io2d/P0267_RefImpl/blob/P0267R8/BUILDING.md
RUN apt update && \
	apt install -y build-essential && \
	apt install -y cmake && \
	apt install -y libncurses5-dev && \
	apt install -y libncursesw5-dev && \
	apt install -y git


# Install VS Code
# See: https://code.visualstudio.com/docs/setup/linux
RUN curl https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > packages.microsoft.gpg && \
	install -o root -g root -m 644 packages.microsoft.gpg /usr/share/keyrings/ && \ 
	sh -c 'echo "deb [arch=amd64 signed-by=/usr/share/keyrings/packages.microsoft.gpg] https://packages.microsoft.com/repos/vscode stable main" > /etc/apt/sources.list.d/vscode.list' && \
	apt-get install apt-transport-https && \
	apt-get update && \
	apt-get install code


