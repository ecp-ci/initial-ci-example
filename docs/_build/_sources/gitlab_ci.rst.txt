GitLab_ and GitLab_ CI
======================

`What is Continuous Integration (CI) testing? <https://bssw.io/items/what-is-continuous-integration-testing>`_

ECP_'s CI resources are based upon `CI functionality <https://about.gitlab.com/product/continuous-integration>`_
of GitLab_.

This section is for people already familiar with GitHub_ and GitHub_'s continuous
integration services and wanting to know more about GitLab_ and GitLab_'s continuous
integration services and what the differences are between the two.

If your project's *home* is as a GitHub_ project...

To use GitLab_ CI services, you will need to do several things

* Import or mirror your project to a GitLab_ instance

  * Then, configure your project in GitLab_ to *mirror* (e.g. stay in sync with its
    GitHub_ origin)

* Add a ``.gitlab-ci.yml`` file in the root directory of your project
* Configure one or more *runners*

Within the context of GitLab, the notion of a `runner <https://docs.gitlab.com/runner/>`_ is a fundamental
aspect of the design. A *runner* is responsible for actually running the jobs that perform CI related
operations.
