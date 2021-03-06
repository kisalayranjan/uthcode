﻿=======================
Version Control Systems
=======================

This is my short introduction to various version control systems.

Git
===

1) git add .
2) git commit

By default, there is a head in every repository called the master.
The currently active head is called HEAD.

A Common git branching usage pattern is to have one main or trunk branch; and
then create branches to add new features. Commonly the master branch is treated
as the main or the trunk branch.

When you want to update your local working copy, you would do:

a) fetch
b) pull

A command similar to svn init
git remote -v

Using submodules
----------------

If the project already has submodules like bloggart

git submodule init
git submodule update

Common Branching Use Patterns in Git
-------------------------------------

A common way to use Git branching is to maintain one “main” or “trunk” branch
and create new branches to implement new features. Often the default Git
branch, master, is used as the main branch. So, in the example above, it may
have been better to leave master at (B), where the paper was submitted to the
reviewers. You could then start a new branch to store changes regarding new
data. Ideally, in this pattern, the master branch is always in a releaseable
state. Other branches will contain half-finished work, new features, and so on.
This pattern is particularly important when there are multiple developers
working on a single project. If all developers are adding commits in sequence
to a single branch, then new features need to be added in a single commit, in
order not to cause the branch to become unusable. However, if each developer
creates a new branch to make a new feature, then commits can be made at any
time, whether or not they are unfinished.

This is what Git users mean when they say that commits are cheap. If you are
working on your own branch, there is no reason you need to be particularly
careful about what you commit to the repository. It won’t affect anything else.

Merge
-----

Merging is done by

git merge [head]
git pull . [head]


Note on terminology: When I say “merge head A into head B,” I mean that head B
is the current head, and you are drawing changes from head A into it.


Common Merge Use Patterns
-------------------------

There are two common reasons to merge two branches. The first, as explained
above, is to draw the changes from a new feature branch into the main branch.

The second use pattern is to draw the main branch into a feature branch you are
developing. This keeps the feature branch up to date with the latest bug fixes
and new features added to the main branch. Doing this regularly reduces the
risk of creating a conflict when you merge your feature into the main branch.

Nomenclature
------------

master is the current repository reference.
origin is the remote repository reference.

How to
------

* How to pull the newly created remote branches?

git checkout --track origin/<remote_branch_name>

Instead of tracking I think, it is better to do

git checkout -b test origin/test

This wll create a local branch called test from the remote branch origin/test

* What to do when you get "Your branch is behind 'origin/master' by 1 commit, and can be fast-forwarded."

To sync your branch with the master you can issue the following command:

  git merge master

  - git merge will not work. You will have to give HEAD name (which is master for the local)

I had to do

  git pull

Workflow
========

git branch

skumaran-tcu
skumaran-rellog

I created skumaran-rellog to work on the release log work.

git checkout skumaran-rellog

After making 10 commits, I did

git rebase -i skumaran-tcu

Then rebased all my commits and then switched branch

git checkout skumaran-tcu

then pulled this one rebased commit.

git merge skumaran-rellog

# Sweet everything is pulled as one commit.
# It does a Fast Forward merge too.

git push 

# This pushed my branch to the remote.


Adding and Deleting Branches Remotely
-------------------------------------

    git push origin new-branch
    git checkout [some-other-branch]
    git branch -f new-branch origin/new-branch
    git checkout new-branch

Git Workflow
------------

http://yehudakatz.com/2010/05/13/common-git-workflows/

HG Terms and Concepts
=====================

Repository (repo)

The dir named .hg in the repository root dir that contains the history of the
project.

Clone

Saving local changes to the repository.

Updating
Applying changes from the repo to the local copy.

Changeset (cset)
An atomic collection of changes to files in a repository.

Pushing/Pulling
Exchanging changesets from a repo to another.

HG is a DVCS
------------
* distributed
* peer-to-peer
* doesn't require a network for most of the operation

HG Basic Usage
--------------

Basic usage

* hg init creates a new repository ...but you won't need this
* hg clone creates a copy of an existing repo:
        hg clone http://hg.python.org/cpython or
        hg clone ssh://hg@hg.python.org/cpython (for committers)
* hg branches to see the list of branches
* hg branch to see the current branch
* hg up <branchname> to change branch.
* hg pull to get the latest changesets in the local repo
* hg up to apply them to the working copy
* hg pull -u to do both at once
* hg stat to see the changed file in the working copy
* hg diff to see the changed code in the working copy
* hg ci -m 'message' to save local changes in the repo
* hg push to send the committed cset to another repo
* hg log -p -r hgchangesetid 
* hg diff -p -r hgchangesetid
 

phoe6: I use separate folders for different branches. I did  push in 2.5 and when I go to 2.6 and do a hg update 2.6 and hg merge 2.5, it says abort: merging with a working directory ancestor has no effect
phoe6: hg incoming has the commit tough
Taggnostr: phoe6, did you manage to merge?
phoe6: no Taggnostr. 
phoe6: Taggnostr: Hi, do you know how to do interbranch merges from 2.5->2.6->2.7 and stop there?
Taggnostr: you have 3 clones, right?
phoe6: yes.
Taggnostr: does hg branch show the right branch for each clone?
phoe6: Yes, it does.
Taggnostr: so you pushed in 2.5, then if you go to 2.6 and do hg pull -u ../2.5; hg merge 2.5; do you get an error?
Taggnostr: also do hg stat and hg diff show anything in 2.6?
phoe6: okay, :) that was the way. To 'pull' the changes into 2.6.
phoe6: Now, I go ahead with push 2.6 and then repeat the process for 2.7 - correct>?
Taggnostr: yep
phoe6: And I need to block this for 3.x codeline and push it from default branch inorder to publish it/
Taggnostr: no need to block
Taggnostr: once you merged it in 2.7 you can just push on the remote repo
phoe6: Taggnostr, I have done a push from 2.7
phoe6: I think, I have to go the default branch and do a push to publish it.
Taggnostr: where did you push? it should say it when you push
Taggnostr: if you cloned from a local repo the pull/push will go to that local repo
Taggnostr: you can edit the [paths] in the .hg/hgrc to pull/push from/to hg.python.org
phoe6: okay, I it is pushing it to my local repo.
Taggnostr: or you can do hg push ssh://...
phoe6: now, that I have pushed it to my local repo, which is the default. I can go there and then do a push to publish.
Taggnostr: yes
Taggnostr: you can check with hg outgoing
phoe6: Yes, hg outgoing has all the changes waiting.
Taggnostr: once you push it should say "pushing to ssh://hg@hg.python.org/" or something similar
phoe6: I have a multi-headed monstor in the default.
Taggnostr: what are the heads?
Taggnostr: (hg heads)
phoe6: abort: push creates new remote heads on branch '2.7'!
phoe6: I did a merge of 2.7 in the 2.7 branch.
phoe6: but still it gives this.
Taggnostr: maybe you haven't pulled
Taggnostr: try to pull from hg.python.org
Taggnostr: I think you changed something in 2.7, someone else changed something on 2.7 and pushed it
Taggnostr: so now you should pull his changes, merge them with yours and then push
gps: don't forget the commit after the merge
Taggnostr: yep, and also the hg up after the pull
phoe6: yeah, I have files edited by someone else when I do a hg diff! :)
phoe6: It seems like I did a hg push; and then I did a hg pull and hg update.
Taggnostr: have you merged yet?
phoe6: abort: outstanding uncommitted merges
Taggnostr: after the merge you have to commit
phoe6: yes, committed.
phoe6: should I push this in? It will push it to the cpython in the local repo.
phoe6: and then push from my local default to publish? 
Taggnostr: yep, try that
Taggnostr: I'm going out for a walk
Taggnostr: looks like it worked :)
Taggnostr: see you later
phoe6: :) Cool. Thanks a lot, Taggnostr.


Mercurial Notes from hginit
---------------------------

hg diff from:to file
hg cat -r revision file
hg update -r revision_to_which_you_want_to_go
Without any arguments,
hg update goes to the latest revision.
hg status gives what was modified in the current repository
hg log will give you the log of file changes.
hg commit -m "mesage"
hg clone URL 
hg outgoing will show the diff of changes which are waiting to go to the outside world.
The one that says use push -f to force? That’s terrible advice. Never, ever, EVER use push -f to force.
hg incoming will say what is coming in.
The first thing I’m going to do is get all those changes that are in the
central repository that I don’t have yet, so I can merge them

Why is pull and update required? After doing pull, one normally does update?
Are there instances when pull is only required and we don't do update?

It’s always safe to pull; all it does is get us the latest changes that other
people have been making. We can switch to working with them later, at our own
convenience.

Where or which changeset are you working on?
hg parent

hg parent shows which changeset you are working off of?

hg revert when you want to revert things for the changes you have done locally but have not committed.
hg rollback for things you have actually committed. But you should rollback and then revert.
(Why the two steps again?)

hg path for where thigns are going.

hg log -l n ( -l last three lines)

push to another repository

hg outgoing http://somecentral.example.com:8000/
hg push http://somecentral.example.com:8000/

Backout an old change

hg backout -r 2 --merge
hg diff
hg com -m "undo a thing from the past"
hg push.

hg annotate is similar to svn blame

--

Wondering what just arrived?

hg log -P .

Will show you what arrived to your mercurial repository when you did a hg pull.

mercurial will resolve merging person to resolve the conflict.

hg tag Something will tag your latest changeset with the *something* as the tag.

hg up -r Something will take you back to the previous version.


subversion and google code
==========================

Setting the property will enable the files to be served from svn.

svn propset svn:mime-type 'text/html' index.html

.css  = svn:mime-type=text/css
.html = svn:mime-type=text/html
.js   = svn:mime-type=text/javascript
.gif  = svn:mime-type=image/gif
.png  = svn:mime-type=image/png

Version Control
===============

https://developer.mozilla.org/en-US/docs/Mercurial_Queues

http://stevelosh.com/blog/2010/08/a-git-users-guide-to-mercurial-queues/#versioned-patch-queues

http://mercurial.selenic.com/wiki/HisteditExtension

I see that i can have a log of commits made to mq while doing refresh.
I wanted to see if I go back and forth using that.
The idea could be that instead of doing refresh I could do hg commit --mq
and I can go back and forth.

Editing History in Mercurial - Strategies

http://mercurial.selenic.com/wiki/EditingHistory

hg diff -r $(hg -R $(hg root)/../../cpython id -i -r tip) > issue10836.patch
hg diff -r `hg -R ../../cpython id -i -r tip`

These two work fine.

hg diff against a revision.
hg id -i # looks redundant but id is a shortform for identify
-i is for global unique identifer.
-r for revision
tip.



hg root
hg diff -r (../../cpython id -i) -r tip
hg diff -r tip
hg diff -r tip^
hg diff -r `hg -R ../../cpython -r tip`
hg diff -r `hg -R ../../cpython id -r tip`
hg diff -r `hg -R ../../cpython id -i -r tip`
hg diff -r `hg -R ../../cpython id -i -r default`

hg workflow

http://blingcode.blogspot.com/2010/12/working-in-git-to-working-in-mercurial.html

you can create 3 different patches.
1. hg import --no-commit ../bug-fixes/something/3.2.patch
2. hg push # this will push to 3.3
3. cd 3.3
4. hg pull -u ../3.2 # is just push and pull. One is no-op.
5. hg merge 3.3 # this will merge.
6. hg revert -ar 3.3 # this will revert only the file changes, but records the merge - Wierd HG.
7. patch -p1 < ../bug-fixes/3.3 patch # this will work.
8. hg commit -m "#42 merge from 3.2"

=======
Git
---

In simplified form, git object storage is "just" a DAG of objects, with a
handful of different types of objects. They are all stored compressed and
identified by an SHA-1 hash (that, incidentally, isn't the SHA-1 of the
contents of the file they represent, but of their representation in git).

blob
----

The simplest object, just a bunch of bytes. This is often a file, but can be a
symlink or pretty much anything else. The object that points to the blob
determines the semantics.

tree
----

Directories are represented by tree object.

git gc
git list-found

for garbage collecting and finding the list of files.

commit
------

A commit refers to a tree that represents the state of the files at the time of
the commit. It also refers to 0..n other commits that are its parents. More
than one parent means the commit is a merge, no parents means it is an initial
commit, and interestingly there can be more than one initial commit; this
usually means two separate projects merged. The body of the commit object is
the commit message.


refs
----

References, or heads or branches, are like post-it notes slapped on a node in
the DAG. Where as the DAG only gets added to and existing nodes cannot be
mutated, the post-its can be moved around freely. They don't get stored in the
history, and they aren't directly transferred between repositories. They act as
sort of bookmarks, "I'm working here".


The HEAD ref is special in that it actually points to another ref. It is a
pointer to the currently active branch. Normal refs are actually in a namespace
heads/XXX, but you can often skip the heads/ part.


Don't rebase branches that others have created new commits on top of. It is
possible to recover from that, it's not hard, but the extra work needed can be
frustrating.

git with merge and rebase

http://eagain.net/articles/git-for-computer-scientists/

http://sitaramc.github.com/gcs/



GIT
===

http://excess.org/article/2008/07/ogre-git-tutorial/
http://www.youtube.com/watch?v=8dhZ9BXQgc4
http://ndpsoftware.com/git-cheatsheet.html#loc=workspace;

Git diff
========

Histogram Diff and Patience Diff

Patience diff goes about match, first common, last common and then doing LCS on middle differing lines.
Histogram extends the same and when doing LCS, it creates the histogram of differences to see the matches.

http://bramcohen.livejournal.com/73318.html

http://www.jarvana.com/jarvana/view/com/madgag/org.eclipse.jgit/0.9.9.1-UNOFFICIAL-ROBERTO-RELEASE/org.eclipse.jgit-0.9.9.1-UNOFFICIAL-ROBERTO-RELEASE-javadoc.jar!/org/eclipse/jgit/diff/HistogramDiff.html

HG
==

1. How to get a set of defaults to hg when you clone?

   Create your .hgrc file.

2. How to switch between different patch queues.
   hg qpop -a
   hg qqueue <another_queue>
   # start working.
   hg qrefresh
   hg qpop -a
   hg qqueue orig-queue
   hg qpush -a

3. In hg. the patches grow from the bottom.

    $ hg qseries
    0 A patch1
    1 A patch2
    $ hg qnew patch3
    $ hg qseries
    0 A patch1
    1 A patch2
    2 A patch3

4. You can add a file in hg queue and then push and pop it?

5. Where does mercurial store it's extension files? 

   /usr/share/pyshared/hgext
