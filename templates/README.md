# Templates Directory

This directory contains starter code templates for the online course. These templates provide a structured starting point for students to work on projects and exercises.

## Structure
- Each template corresponds to a specific lesson or exercise in the course.
- File names indicate the relevant topic or module.

## Usage
1. Copy the necessary template files into your working directory.
2. Follow the instructions provided in the course material.
3. Implement the missing functionality as required.

## Cloning The Repository
Because these templates are part of a larger repository, you have to clone specific templates. Unfortunately this is not directly suppored via GitHub, but there is a work-around. To do so, execute the following commands:

```sh
# clone the repository with no files checked out initially:
git clone --no-checkout --depth 1 --filter=blob:none https://github.com/ethanokamura/courses/
# navigate into the repo
cd courses
# enable sparse checkout
git sparse-checkout init --cone
# specify the subdirectory you want to clone (ie templates/maze)
git sparse-checkout set templates/maze
# checkout the files
git checkout
```

Now, only the `templates/maze` directory will be available in your local copy.

