#!/bin/bash
echo "seqno contains: $(cat seqno)"
./exercise5 100 &
./exercise6 100 
echo "seqno contains: $(cat seqno)"


