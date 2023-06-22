#!/bin/bash

# Check if a file name and commit message were provided
if [ -z "$1" ] || [ -z "$2" ]
then
    echo "Please provide a file name and a commit message"
    exit 1
fi

# Add the specified file to the staging area
git add "$1"

# Commit the changes with the provided message
git commit -m "$2"

# Push the changes to the remote repository
git push
