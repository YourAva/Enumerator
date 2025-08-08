# Enumerator 🔍

This is a simple nMap wrapper program for inital target enumeration. It allows for deep scanning of a target and its running processes at the highest of speeds by doing a fast scan to find what ports are open and then properly checking those ports and their processes spesifically in a deeper scan. To make myself clear. This is just a wrapper program and has **no links to the [original nMap program](https://github.com/nmap/nmap) or its contributors**.

## Installation
Installation is quite simple. Take the built binary and move it to wherever you want to run it. I'd recommend ``/bin`` so it can be ran from anywhere. Your final command should look something like this:
```
sudo mv enumerator /bin
```

## Tutorial
Enumerator is quite a simple tool. You just run it and provide an IP to run a baseline scan on. However, if you're running into errors on your target that require arguments to fix such as ``-sV`` you can add any nmap command to the scans by adding it to the enumerator cli argument. For example, if we wanted to provide the ``-sV`` argument to all of our scans through enumerator, we'd do so like this...
```
enumerator {ip} -sV
```


## Final Notes
This is just a nicer version of the code I've been using to do my prior enumeration of a target. It isn't perfect. Some changes may be made to fix it but right now It's not properly maintained.
