#!/bin/sh

git config --global http.proxy http://proxy.uec.ac.jp:8080
export http_proxy=http://proxy.uec.ac.jp:8080/
export https_proxy=http://proxy.uec.ac.jp:8080/
export ALL_PROXY=http://proxy.uec.ac.jp:8080/
