#!/usr/bin/env bash
# Script to run the unit test generator

set -e
# Ensure required directories exist
mkdir -p generator/prompts tests
# Execute the test generator
python3 generator/generate_tests.py 