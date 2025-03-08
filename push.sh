#!/bin/bash
read -p 'Subject ID (0-4): ' subjectID

subjectList=("Theory" \
    "Languages/C++" \
    "Languages/Java" \
    "Languages/Go" \
    "Platform/LeetCode" \
    "Platform/GeeksForGeeks" \
    "Platform/College-1")

subjectName=${subjectList[$((subjectID))]}

# Subject file name formatting
extension="md"
if [ "$subjectID" -eq 0 ]; then
    targetFile="$subjectName.$extension"
elif [ "$subjectID" -ge 1 ] && [ "subjectID" -le 5 ]; then
    targetFile="$(echo $subjectName | awk -F'/' '{print $1}').$extension"
    targetCodeDir="$(echo $subjectName | awk -F'/' '{print $2}')"
fi

# Commit message formatting
commitMessage="update: $subjectName"

# push to repository
if [ "$subjectID" -eq 0 ]; then                             
    git add README.md ./notes/$targetFile
elif [ "$subjectID" -ge 1 ] && [ "$subjectID" -le 3 ]; then
    git add README.md ./notes/$targetFile ./self/$targetCodeDir/
elif [ "$subjectID" -ge 4 ] && [ "$subjectID" -le 6 ]; then
    git add README.md ./notes/$targetFile ./platform/$targetCodeDir/
fi

git commit -m "$commitMessage"
git push origin main
