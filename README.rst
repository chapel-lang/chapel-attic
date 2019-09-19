.. image:: https://chapel-lang.org/images/cray-chapel-logo-200.png
    :align: center

The Chapel Language
===================

What is Chapel?
---------------
Chapel is a modern programming language designed for productive
parallel computing at scale. Chapel's design and implementation have
been undertaken with portability in mind, permitting Chapel to run on
multicore desktops and laptops, commodity clusters, and the cloud, in
addition to the high-end supercomputers for which it was originally
undertaken.

What is Quiescent-State Based Reclamation?
------------------------------------------
Quiescent State-Based Reclamation (QSBR), is a type of concurrent-safe
memory reclamation mechanism that is used to track the lifetimes of
an arbitrary number of objects. Objects, which are first logically
removed from a data structure, i.e. a removed node form a linked list,
have a lifetime tied to the quiescence of all participating threads.
Quiescence, unlike most approaches to concurrent-safe memory reclamation,
is not implicit, but explicit. To provide a comparison: In Epoch-Based
Memory Reclamation (EBR), a thread or task is quiescent until they enter a
read-side critical section, or `pin`. With QSBR, all threads or tasks are
_not_ quiescent, meaning they are considered to have access to that data,
until they explicitly signal that they are quiescent. This means that data
cannot be reclaimed, even if no thread is accessing the data in question
at that time, but it has the benefit that accessing the data has zero-overhead,
i.e. no cost to enter a read-side critical section. The trade-off is potential
memory leakage if quiescence is not signaled often enough, or if a single thread
or task never signals that they are quiescent.

Currently, it is used in `chpl-privatization.c` to fix a memory leakage when
the privatization table gets resized. It can be used outside of the runtime,
as shown in test/memory/qsbr and test/distributions/privatization/runtime; implementation of QSBR can be seen in both
runtime/src/chpl-qsbr.c and runtime/include/chpl-qsbr.h.

TODO for QSBR
-------------

1. Need better integration with uGNI and GASNet communication layer
2. Needs more rigorous testing for portability.

License
-------
Chapel is developed and released under the terms of the Apache 2.0
license, though it also makes use of third-party packages under their
own licensing terms.  See the `LICENSE`_ file in this directory for
details.

Resources
---------
For more information about Chapel, please refer to the following resources:

.. NOTE
   If you are viewing this file locally, we recommend referring to
   doc/README.rst for local references to documentation and resources.

=====================  ========================================================
Project homepage:      https://chapel-lang.org
Installing Chapel:     https://chapel-lang.org/download.html
Building from source:  https://chapel-lang.org/docs/usingchapel/QUICKSTART.html
Sample computations:   https://chapel-lang.org/hellos.html
Learning Chapel:       https://chapel-lang.org/learning.html
Reporting bugs:        https://chapel-lang.org/bugs.html
Online documentation:  https://chapel-lang.org/docs/
GitHub:                https://github.com/chapel-lang/chapel
Mailing lists:         https://sourceforge.net/p/chapel/mailman
Facebook:              https://www.facebook.com/ChapelLanguage
Twitter:               https://twitter.com/ChapelLanguage
=====================  ========================================================

