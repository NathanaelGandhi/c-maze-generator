################################################################################
# Title:  Development Container for C projects
# Author: Nathanael Gandhi | https://github.com/NathanaelGandhi
# Notes:  Container for all project dependencies. Build with either Docker or 
#         Podman. Intended to be run using Distrobox or VSCode Dev Container.
################################################################################
# Build Instructions Podman/Distrobox:  
#   Image:  podman build -t <image-name> -f <path>/Containerfile.dev.C .
#   Cont:   distrobox create <container-name> -i <image-name>
#   Run:    distrobox enter <container-name>      
################################################################################
# Build Instructions Docker/VSCode Dev Container:  
#   VSCode:    Reopen folder in Container
################################################################################
# Base Configuration
FROM ubuntu:22.04
ENV LANG C.UTF-8
ENV LC_ALL C.UTF-8
################################################################################
# Update apt
RUN apt-get update
################################################################################
# Use cached packages if available
# Note: on-host ```sudo apt install apt-cacher-ng```
ARG USE_CACHED_APT_PACKAGES='true'
RUN if [ "$USE_CACHED_APT_PACKAGES" = "true" ]; then \
        echo "Using cached apt packages if available"; \
        apt-get install auto-apt-proxy -y && auto-apt-proxy; \
     else \
        echo "Not using cached apt packages"; \
    fi
################################################################################
# Install user tools
RUN apt-get install -y \
	git nano tree
################################################################################
# Install extend & theme ZSH shell
RUN apt-get install -y wget zsh fonts-powerline && \
	echo "[config-zsh] installing oh-my-zsh" && \
	wget https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh -O - | zsh || true && \
	echo "[config-zsh] installing oh-my-zsh plugins" && \
	git clone https://github.com/zsh-users/zsh-autosuggestions ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-autosuggestions && \
	git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-syntax-highlighting && \
	sed -i 's|plugins=(git)|plugins=(git zsh-autosuggestions zsh-syntax-highlighting)|g' ~/.zshrc && \
	echo "[config-zsh] setting theme to agnoster" && \
	sed -i 's|ZSH_THEME="robbyrussell"|ZSH_THEME="agnoster"|g' ~/.zshrc && \ 
	sed -i 's|echo -n "%{%f%}"|echo -n "\n[%D{%H:%M:%S}] >%{%f%}"|g' ~/.oh-my-zsh/themes/agnoster.zsh-theme
# Run zsh on container start
CMD [ "zsh" ]
################################################################################
# Install project tools
RUN apt install -y \ 
	gcc g++ make cmake clang-format
################################################################################