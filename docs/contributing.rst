.. _Contributing:

Contributing
============

The TrainingCi4Ecp site is using
`Sphinx <http://www.sphinx-doc.org/en/stable/tutorial.html>`_ for
documentation.

If you have `Sphinx <http://www.sphinx-doc.org/en/stable/tutorial.html>`_ You can
build the documentation site locally using the command::

    sphinx-build -b html . _build -a

You can then browse the root of the manual by pointing your browser to
:file:`./_build/index.html`.  The ``-a`` forces a re-build of everything.
Remove it when you are constantly revising and rebuilding.

Your changes to any files in :file:`docs` will go live
`here <http://visit-sphinx-user-manual.readthedocs.io/en/latest/index.html>`_
shortly after you push your commits to GitHub. GitHub uses ReadTheDocs to
build the documentation pages from the Restructured Text, ``.rst`` sources.

Quick Reference
---------------

* A few documents about reStructuredText and Sphinx are useful:

  * `reStructuredText Primer <http://docutils.sourceforge.net/docs/user/rst/quickref.html>`_
  * `Sphinx Documentation <http://www.sphinx-doc.org/en/stable/contents.html>`_
  * `reStructuredText Markup Specification <http://docutils.sourceforge.net/docs/ref/rst/restructuredtext.html>`_
  * `reStructuredText Reference Documentation <http://docutils.sourceforge.net/rst.html#reference-documentation>`_

* Sphinx uses blank lines as block separators and 2 or 4 spaces of
  indentation to guide parsing and interpretation of content. So, be sure
  to pay careful attention to blank lines and indentation. They are not
  there merely for style.  They *need* to be there for Sphinx to parse and
  interpret the content correctly.
* Line breaks *within* reStructuredText inline markup constructs often cause
  build errors. 
* Create headings by a sequence of *separator characters* immediately
  underneath and the same length as the heading. Different types of
  separator characters define different levels of headings ::

    First Level Heading
    ===================
    This is an example of some text under the heading...

    Second Level Heading
    --------------------
    This is an example of some text under the heading...

    Third Level Heading
    ~~~~~~~~~~~~~~~~~~~
    This is an example of some text under the heading...

    Fourth level heading
    """"""""""""""""""""
    This is an example of some text under the heading...

  yields these headings...

.. figure:: images/headings.png

* If you want to divide sections and subsections across multiple ``.rst``
  files, you can link them together using the ``.. toctree::`` directive
  as is done for example in the section on VisIt_ **Plots** ::

    Examples 
    ========
 
    This chapter describes various examples and goes into details about
    each example.
 
    .. toctree::
        :maxdepth: 1
 
        Various CI Examples
        Examples/index

  Note that the files listed in the ``.. toctree::`` block do not include
  their ``.rst`` extensions.

* Wherever possible, keep lines in ``.rst`` files to 80 columns or less.
* Avoid contractions such as ``isn't``, ``can't`` and ``you've``.
* Avoid hyphenation of words.
* Use ``VisIt_`` or ``VisIt_'s`` when referring to VisIt_ by name.
* Use upper case for all letters in acronyms (:abbr:`MPI (Message Passing Interface)`, VTK)
* Use case conventions of product names (QuickTime, TotalView, Valgrind).
* Bracket word(s) with two stars (``**some words**``) for **bold**.
* Bracket word(s) with one star (``*word*``) for *italics*.
* Bracket word(s) with two backticks (:samp:`\ ``some words```) for ``literal``.
* Bracketed word(s) should not span line breaks.
* Use **bold** to refer to VisIt_ **Widget** names, **Operator** or **Plot**
  names and other named objects part of VisIt_'s interface.
* Avoid use of **bold** for other purposes. Instead use *italics*.
* Use ``literals`` for code, commands, arguments, file names, etc.
* Use :samp:`\ :t\ erm:`glossary term`` at least for the *first* use of a
  glossary term in a section.
* Use :samp:`\ :a\ bbr:`ABR (Long Form)`` at least for the *first* use of an
  acronym or abbreviation in a section.
* Subscripting, H\ :sub:`2`\ O, and superscripting, E = mc\ :sup:`2`, are supported::

    Subscripting, H\ :sub:`2`\ O, and superscripting, E = mc\ :sup:`2`, are supported

  Note the use of backslashed spaces so Sphinx treats it all as one word.
* Use ``.. figure::`` and not ``.. image::``, include captions with figures
  and use ``:scale: P %`` to adjust image size where needed
  (:ref:`see more below <contributing_images>`).
* LaTeX style equations can be included too
  (:ref:`see below <contributing_math>`).
* Begin a line with ``..`` followed by space for single line comments::

    .. this is a single line comment

    ..
        This is a multi-line
        comment

.. _my_anchor:

* Define anchors ahead of sections or paragraphs you want to cross reference::

    .. _my_anchor:

    Section Heading
    ---------------

  Note that the leading underscore is **not** part of the anchor name.
* Make anchor names unique over *all* pages of documentation by using
  the convention of prepending heading and subheading names.
* Link to anchors *within* this documentation like :ref:`this one <my_anchor>`::

    Link to anchors *within* this documentation like :ref:`this one <my_anchor>`

* Link to other documents elsewhere online like
  `visitusers.org <https://www.visitusers.org/>`_::

    Link to other documents elsewhere online like
    `visitusers.org <https://www.visitusers.org/>`_

* Link to *numbered* figures or tables *within* this documentation like
  :numref:`Fig. %s <my_figure2>`::

    Link to *numbered* figures or tables *within* this documentation like
    :numref:`Fig. %s <my_figure2>`

* Link to a downloadable file *within* this documentation like
  :download:`this one <../Quantitative/VerdictManual-revA.pdf>`::

    Link to a downloadable file *within* this documentation like
    :download:`this one <../Quantitative/VerdictManual-revA.pdf>`

.. _contributing_images:

More on Images
--------------

Try to use PNG formatted images. We plan to use the Sphinx generated
documentation both for online HTML and for printed PDF. So, images sizes
cannot be too big or they will slow HTML loads but not so small they are
unusable in PDF.

Some image formats wind up enforcing **physical** dimensions instead of
just pixel dimensions. This can have the effect of causing a nicely sized
image (from pixel dimensions perspective anyways), to either be unusually
large or unusually small in HTML or PDF output. In these cases, you can
use the Sphinx ``:scale:`` and ``:width:`` or ``:height:`` options for
a ``.. figure::`` block. Also, be sure to use a ``.. figure::`` directive
instead of an ``.. image::`` directive for embedding images. This is because
the ``.. figure::`` directive also supports anchoring for cross referencing.

Although all images get copied into a common directory during generation,
Sphinx takes care of remapping names so there is no need to worry about
collisions in image file names potentially used in different subdirectories
within the source tree.

An ordinary image...

.. code-block:: RST

  .. figure:: images/array_compose_with_bins.png

.. figure:: images/array_compose_with_bins.png

Same image with ``:scale: 50%`` option

.. code-block:: RST

  .. figure:: images/array_compose_with_bins.png
     :scale: 50% 

.. figure:: images/array_compose_with_bins.png
   :scale: 50% 

Same image with an anchor for cross referencing...

.. code-block:: RST

  .. _my_figure:

  .. figure:: images/array_compose_with_bins.png
     :scale: 50% 

.. _my_figure:

.. figure:: images/array_compose_with_bins.png
   :scale: 50% 

which can now be cross referenced using an inline :numref:`Fig. %s <my_figure>` 
like so...

.. code-block:: RST

  Which can now be cross referenced using an inline :numref:`Fig. %s <my_figure>` 
  like so...

Note the anchor has a leading underscore which the reference does not include.

Same image (different anchor though because anchors need to be unique) with
a caption.

.. code-block:: RST

  .. _my_figure2:

  .. figure:: images/array_compose_with_bins.png
     :scale: 50% 

     Here is a caption for the figure.

.. _my_figure2:

.. figure:: images/array_compose_with_bins.png
   :scale: 50% 

   Here is a caption for the figure.

Note that the figure label (e.g. Fig 20.2) will not appear if there is no
caption.

Tables
------
Sphinx supports a variety of mechanisms for defining tables. The conversion
tool used to convert this documentation from its original OpenOffice format
converted all tables to the *grid* style of table which is kinda sorta like
ascii art. Large tables can result in individual lines that span many widths of
the editor window. It is cumbersome to deal with but rich in capabilities.

.. _contributing_math:

Math
----

We add the Sphinx builtin extension ``sphinx.ext.mathjax`` to the
``extensions`` variable in ``conf.py``. This allows Sphinx to use
`mathjax <https://www.mathjax.org>`_ to do LaTeX like math equations in our
documentation. For example, this LaTeX code

.. code-block:: RST

  :math:`x=\frac{-b\pm\sqrt{b^2-4ac}}{2a}`

produces...

:math:`x=\frac{-b\pm\sqrt{b^2-4ac}}{2a}`

You can find a few examples in :ref:`Expressions <Expressions>`. Search
there for `:math:`. Also, this
`LaTeX Wiki page <https://oeis.org/wiki/List_of_LaTeX_mathematical_symbols>`_
has a lot of useful information on various math symbols available in LaTeX
and `this wiki book <https://en.wikibooks.org/wiki/LaTeX/Mathematics>`_ has
a lot of guidance on constructing math equations with LaTeX.

