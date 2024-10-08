% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/C_Variable.R
\name{C_Variable}
\alias{C_Variable}
\title{CHSM Variable Object}
\description{
A Variable in a composite Hierarchy State Machine

  Implementation is provided by C++ objects.
}
\section{Super class}{
\code{\link[rchsm:C_Object]{rchsm::C_Object}} -> \code{C_Variable}
}
\section{Methods}{
\subsection{Public methods}{
\itemize{
\item \href{#method-C_Variable-new}{\code{C_Variable$new()}}
\item \href{#method-C_Variable-getValueString}{\code{C_Variable$getValueString()}}
\item \href{#method-C_Variable-clone}{\code{C_Variable$clone()}}
}
}
\if{html}{\out{
<details open><summary>Inherited methods</summary>
<ul>
<li><span class="pkg-link" data-pkg="rchsm" data-topic="C_Object" data-id="callFunction"><a href='../../rchsm/html/C_Object.html#method-C_Object-callFunction'><code>rchsm::C_Object$callFunction()</code></a></span></li>
</ul>
</details>
}}
\if{html}{\out{<hr>}}
\if{html}{\out{<a id="method-C_Variable-new"></a>}}
\if{latex}{\out{\hypertarget{method-C_Variable-new}{}}}
\subsection{Method \code{new()}}{
Constructs an object that is a new instance of the class
\subsection{Usage}{
\if{html}{\out{<div class="r">}}\preformatted{C_Variable$new(className = "Variable", ..., regFinalizer, .external = NULL)}\if{html}{\out{</div>}}
}

\subsection{Arguments}{
\if{html}{\out{<div class="arguments">}}
\describe{
\item{\code{className}}{(Optional) Name of the class used in accessing c++ functions.
Default value is "Holon"}

\item{\code{...}}{Abstract arguments passed to the constructor of the super class}

\item{\code{regFinalizer}}{Logical to indicate if a finalizer should be registered (TRUE)
or not (FALSE).
See super class C_Object for more information.}

\item{\code{.external}}{(Optional) If an external pointer is provided instead of the default
NULL value, then the new R6 object will be associated with the 
existing C++ Object referenced by the pointer.}
}
\if{html}{\out{</div>}}
}
}
\if{html}{\out{<hr>}}
\if{html}{\out{<a id="method-C_Variable-getValueString"></a>}}
\if{latex}{\out{\hypertarget{method-C_Variable-getValueString}{}}}
\subsection{Method \code{getValueString()}}{
Get the value of the variable as a character string
\subsection{Usage}{
\if{html}{\out{<div class="r">}}\preformatted{C_Variable$getValueString()}\if{html}{\out{</div>}}
}

\subsection{Returns}{
A single element character vector representing the value.
}
}
\if{html}{\out{<hr>}}
\if{html}{\out{<a id="method-C_Variable-clone"></a>}}
\if{latex}{\out{\hypertarget{method-C_Variable-clone}{}}}
\subsection{Method \code{clone()}}{
The objects of this class are cloneable with this method.
\subsection{Usage}{
\if{html}{\out{<div class="r">}}\preformatted{C_Variable$clone(deep = FALSE)}\if{html}{\out{</div>}}
}

\subsection{Arguments}{
\if{html}{\out{<div class="arguments">}}
\describe{
\item{\code{deep}}{Whether to make a deep clone.}
}
\if{html}{\out{</div>}}
}
}
}
