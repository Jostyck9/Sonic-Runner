# Sonic Runner
A runner platformer game. This project is a game compatible with Linux.

## Installation

To download the repository, you just need to clone it from Github:

```sh
$ git clone https://github.com/Jostyck9/Sonic-Runner.git
$ cd Sonic-Runner/
```

## Compilation
You need to have CSFML installed on your computer

To compile on Linux, use your terminal to install CSFML (using bash or equivalent)

```sh
$ ./install_csfml.sh
```

After that, restart your terminale and you just need to compile with the makefile and launch your game !

```sh
$ make
$ ./my_runner map.txt
```

## Usage

This game is a full keyboard usage. You cannot use your mouse.
To deplace use the directional arrows.
To jump use space.

To win, you have to touch the final flag.
Be careful of the spikes ;)

### Map

This game support a map customization, you can found the legend in the .legend file.