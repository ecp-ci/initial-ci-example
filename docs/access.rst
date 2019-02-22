Getting Access To ECP_ CI Systems
=================================

`What is Continuous Integration (CI) testing? <https://bssw.io/items/what-is-continuous-integration-testing>`_

ECP_'s CI resources are based upon `CI functionality <https://about.gitlab.com/product/continuous-integration>`_
of `GitLab <https://docs.gitlab.com>`_.

Each site that offers CI resources to ECP_ projects does so via a local GitLab instance.

Within the context of GitLab, the notion of a `runner <https://docs.gitlab.com/runner/>`_ is a fundamental
aspect of the design. A *runner* is responsible for actually running the jobs that perform CI related
operations.
