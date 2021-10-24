import os
from setuptools import find_packages
from setuptools import setup

setup(
    name='droneinterfaces',
    version='0.0.0',
    packages=find_packages(
        include=('droneinterfaces', 'droneinterfaces.*')),
)
