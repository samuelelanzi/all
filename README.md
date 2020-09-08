# Come usare git

Creare una cartella `myRepository`:

```
mkdir myRepository
cd myRepository
git clone https://github.com/username/myGitHubRepositoryName
touch filename.cpp
gedit filename.cpp
git status
git add filename.cpp
git status 
git commit -m "Some Text" filename.cpp
git push -u origin master
```

Il file verra' aggiunto nella repository `git`
