#!/bin/sh

touch .gitignore
echo '*.save' >> .gitignore
echo '.gitignore' >> .gitignore

git init
git add -A
git commit -m "Initial commit"
