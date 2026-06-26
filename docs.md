*this file contains organizational information for the cub3d project*

# Git Cheatsheet

## Daily routine
	git checkout main
	git pull --ff-only origin main		//ff: without creating an extra merge commit
	git checkout <branch-name>
	git merge main
	git status
	git diff
	git add <file>
	git diff --staged
	git commit -m "VERB description"
	git push

## New branch
	git checkout main
	git pull --ff-only origin main
	git checkout -b <owner>/<feature-name>
	git push -u origin <owner>/<feature-name>

## Delete merged branch
	git checkout main
	git pull --ff-only origin main
	git branch -d <branch-name>
	git push origin --delete <branch-name>
	git fetch --prune

## Merge conflict
	git status
	git add <file>
	git commit -m "FIX merge conflict: resolve changes"

