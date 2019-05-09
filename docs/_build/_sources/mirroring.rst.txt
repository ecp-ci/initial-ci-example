Repository Mirroring
====================

In Git, repository *mirroring* is the creation of a copy of a repository 
in another Git instance. The *mirror* (or copy) is intended to just follow
along with all the work happening in the original repository.

Mirroring via Git hosting provider interface
--------------------------------------------

Each Git hosting provider (e.g. GitHub_, GitLab_, Bitbucket, etc.) may offer
built-in support for repository mirroring in their hosted repository controls.
For example, in most GitLab_ instances, you can find mirroring controls under
:menuselection:`Settings --> Repository --> Mirroring repositories --> Expand`
as shown in the screenshot...

.. figure:: files/gitlab_mirror_controls.png
   :scale: 50%

However, not all GitLab_ hosting providers support **both** a *push* mode and *pull*
mode for mirroring. Most provide only a *push* mode meaning you can set up the
controls to push code *out* from the GitLab_ instance but not pull it *in*.

Since access to each ECP_ CI resource is controlled by a local GitLab_ instance,
most ECP_ code teams will be looking for a way to mirror their code *into* those
instances. Bottom line, you won't be able to do it by using the GitLab_ hosting
providers built-in mirroring feature. Instead, you will have to handle this manually
by using a clone as an intermediary. But this is very simple

Mirror via Git Clone as Intermediary
------------------------------------

To achieve the end goal of mirroring an existing repository into an ECP_ CI
GitLab_ instance, you would use a Git clone as an intermediary an set up
the remotes for the clone such that you can ``get pull`` from the source
repository and then ``git push`` to the GitLab_ repository.
