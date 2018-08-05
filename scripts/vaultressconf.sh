#!/bin/bash -ev

mkdir -p ~/.vaultress
echo "rpcuser=username" >>~/.vaultress/vaultress.conf
echo "rpcpassword=`head -c 32 /dev/urandom | base64`" >>~/.vaultress/vaultress.conf

