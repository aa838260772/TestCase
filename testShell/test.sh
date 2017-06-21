#!/bin/bash
shopt -s extglob

arget="c|d"
target="@($arget)"

if (( $# == 0 ))
then
	echo "./test.sh num"
	exit 1
fi

case $1 in
	a)
		echo "a"
		;;
	b)
		echo "b"
		;;
	$target)
		echo "target"
		;;
	*)
		echo "err"
esac

