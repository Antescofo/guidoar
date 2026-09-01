#!/bin/bash

set -euo pipefail

transpose_tool="${1:-../build/bin/guidotransposei}"

if [ ! -x "${transpose_tool}" ]; then
	echo "Missing guidotransposei executable: ${transpose_tool}" >&2
	exit 1
fi

assert_transposition() {
	local description="$1"
	local score="$2"
	local interval="$3"
	local expected="$4"
	local actual

	actual=$("${transpose_tool}" "${score}" "${interval}" | tr -d '[:space:]')
	if [ "${actual}" != "${expected}" ]; then
		echo "FAILED: ${description}" >&2
		echo "Expected: ${expected}" >&2
		echo "Actual:   ${actual}" >&2
		exit 1
	fi
}

assert_transposition \
	"Ordinary E-flat-instrument transposition keeps three sharps" \
	'[ \key<0> c d e f g a b c ]' \
	9 \
	'{[\key<3>abc#2def#g#a1]}'

assert_transposition \
	"Five sharps remain conventionally spelled" \
	'[ \key<2> d e f# g a b c# d ]' \
	9 \
	'{[\key<5>bc#2d#ef#g#a#1b]}'

assert_transposition \
	"Six sharps remain conventionally spelled" \
	'[ \key<3> a b c# d e f# g# a ]' \
	9 \
	'{[\key<6>f#2g#a#1bc#2d#e#f#]}'

assert_transposition \
	"Seven sharps remain conventionally spelled" \
	'[ \key<4> e f# g# a b c# d# e ]' \
	9 \
	'{[\key<7>c#2d#e#f#g#a#1b#c#2]}'

assert_transposition \
	"Eight sharps use the four-flat enharmonic spelling" \
	'[ \key<5> b c# d# e f# g# a# b ]' \
	9 \
	'{[\key<-4>a&2b&1c2d&e&fga&]}'

assert_transposition \
	"Seven flats remain conventionally spelled" \
	'[ \key<-7> c& d& e& f& g& a& b& c& ]' \
	0 \
	'{[\key<-7>c&d&e&f&g&a&b&c&]}'

assert_transposition \
	"F-flat spellings follow an enharmonic change to E major" \
	'[ \key<-4> a& b& c d& e& f g a& ]' \
	8 \
	'{[\key<4>e2f#g#1abc#2d#e]}'

assert_transposition \
	"A later key change resets the note spelling" \
	'[ \key<5> b c# \key<-3> e& f g a& ]' \
	9 \
	'{[\key<-4>a&2b&1\key<0>c2def]}'

assert_transposition \
	"Each voice applies its own key spelling" \
	'{ [ \key<5> b c# ] , [ \key<5> d# e ] }' \
	9 \
	'{[\key<-4>a&2b&1],[\key<-4>c2d&]}'

echo "All enharmonic transposition tests passed."
