#!/bin/sh

git config --global --unset http.proxy http://proxy.uec.ac.jp:8080
unset http_proxy
unset https_proxy
unset ALL_PROXY

