To run

#Make sure tor is started
sudo systemctl start tor.service

#start vaultress daemon with tor as proxy
ONIONHOSTNAME=$(sudo cat /var/lib/tor/vaultress-service/hostname)
./vaultressd -daemon -proxy=127.0.0.1:9050 -bind=127.0.0.1 -externalip=${ONIONHOSTNAME}
