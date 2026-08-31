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
	"C-sharp major is respelled consistently as D-flat major" \
	'[ \key<4> e f# g# a b c# d# e ]' \
	9 \
	'{[\key<-5>d&2e&fg&a&b&1c2d&]}'

assert_transposition \
	"F-flat spellings follow an enharmonic change to E major" \
	'[ \key<-4> a& b& c d& e& f g a& ]' \
	8 \
	'{[\key<4>e2f#g#1abc#2d#e]}'

assert_transposition \
	"A later key change resets the note spelling" \
	'[ \key<4> e f# \key<-3> e& f g a& ]' \
	9 \
	'{[\key<-5>d&2e&\key<0>cdef]}'

assert_transposition \
	"Each voice applies its own key spelling" \
	'{ [ \key<4> e f# ] , [ \key<4> g# a ] }' \
	9 \
	'{[\key<-5>d&2e&],[\key<-5>f2g&]}'

echo "All enharmonic transposition tests passed."
