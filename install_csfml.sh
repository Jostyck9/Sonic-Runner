#!/usr/bin/env bash

set -e

SFML_VERSION='2.3'
GLEW_VERSION='1.10.0'

add_to_rc_if_not_exist()
{
	local rc_filename="$1"
	local to_add="$2"

	grep -q -F "$to_add" "$rc_filename" || echo "export" "$to_add" >> "$rc_filename"
}

have_rc()
{
	if [ -f ~/."$1"rc ]
	then
		return 0
	else
		return 1
	fi
}

rc_path()
{
	echo ~/."$1"rc
}

add_to_rcs_if_not_exist()
{
	if have_rc "bash"; then
		add_to_rc_if_not_exist "$(rc_path bash)" $1
	fi

	if have_rc "zsh"; then
		add_to_rc_if_not_exist "$(rc_path zsh)" $1
	fi

	if [ -f ~/.config/fish/config.fish ]; then
		add_to_rc_if_not_exist ~/.config/fish/config.fish $1
	fi

	if have_rc "tcsh"; then
		add_to_rc_if_not_exist "$(rc_path tcsh)" $1
	fi
}

add_lib_to_rc()
{
	local lib_name="$1"
	local lib_path="$HOME/.libs/$lib_name"

	add_to_rcs_if_not_exist "LIBRARY_PATH=\$LIBRARY_PATH:$lib_path/lib"
	add_to_rcs_if_not_exist "LD_LIBRARY_PATH=\$LIBRARY_PATH:$lib_path/lib"
	add_to_rcs_if_not_exist "CPATH=\$CPATH:$lib_path/include"
}

get_file()
{
	local file_to_get="$1"
	local filename=$(echo $file_to_get | sed -e 's/.*\///')

	if ! [[ -f $filename ]]; then
		wget "$file_to_get"
	else
		echo "-------- $filename already exists locally, skipping..."
	fi

	extract_archive $filename
}

extract_archive()
{
	local file_to_extract="$1"
	echo "extracting $file_to_extract..."
	tar -xf $file_to_extract
}

DOWNLOAD_LOCATION=$(pwd)
get_file "http://www.sfml-dev.org/files/CSFML-$SFML_VERSION-linux-gcc-64-bit.tar.bz2"
get_file "http://www.sfml-dev.org/files/SFML-$SFML_VERSION-linux-gcc-64-bit.tar.gz"
get_file "https://sourceforge.net/projects/glew/files/glew/$GLEW_VERSION/glew-$GLEW_VERSION.tgz"

mkdir -p ~/.libs
rm ~/.libs/"SFML-$SFML_VERSION" ~/.libs/"CSFML-$SFML_VERSION" ~/.libs/"glew-$GLEW_VERSION" -rf
mv "CSFML-$SFML_VERSION" "SFML-$SFML_VERSION" "glew-$GLEW_VERSION" ~/.libs/

sudo apt install libx11-dev libxmu-dev libxi-dev libgl-dev libopenal-dev
cd ~/.libs/"glew-$GLEW_VERSION"
make

add_lib_to_rc "CSFML-$SFML_VERSION"
add_lib_to_rc "SFML-$SFML_VERSION"
add_lib_to_rc "glew-$GLEW_VERSION"

cd "$DOWNLOAD_LOCATION"
rm -f "SFML-$SFML_VERSION-linux-gcc-64-bit.tar.gz" "CSFML-$SFML_VERSION-linux-gcc-64-bit.tar.bz2" "glew-$GLEW_VERSION.tgz"

echo -e "\n\n"
echo "CSFML $SFML_VERSION has been installed"
echo "Please remember to add -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system in your Makefile"
echo
echo "2017 - Paul Laffitte - Epitech Montpellier Promo 2021"