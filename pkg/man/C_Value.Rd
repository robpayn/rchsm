% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/C_Value.R
\name{C_Value}
\alias{C_Value}
\title{Value Object}
\description{
An R6 class mapping to a C++ Value object

  Implementation is provided by C++ objects.
}
\section{Super class}{
\code{\link[rchsm:C_Object]{rchsm::C_Object}} -> \code{C_Value}
}
\section{Methods}{
\subsection{Public methods}{
\itemize{
\item \href{#method-C_Value-new}{\code{C_Value$new()}}
\item \href{#method-C_Value-clone}{\code{C_Value$clone()}}
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
\if{html}{\out{<a id="method-C_Value-new"></a>}}
\if{latex}{\out{\hypertarget{method-C_Value-new}{}}}
\subsection{Method \code{new()}}{
Create a new instance of a Value class
\subsection{Usage}{
\if{html}{\out{<div class="r">}}\preformatted{C_Value$new(className, ..., regFinalizer = FALSE)}\if{html}{\out{</div>}}
}

\subsection{Arguments}{
\if{html}{\out{<div class="arguments">}}
\describe{
\item{\code{className}}{Character string with the name of the type of value to be created}

\item{\code{...}}{Generic arguments passed on to the value constructor.}

\item{\code{regFinalizer}}{(Optional) Logical to indicate if a finalizer should be registered 
(TRUE) or not (FALSE).
Defaults to FALSE.
See super class C_Object for more information.}
}
\if{html}{\out{</div>}}
}
}
\if{html}{\out{<hr>}}
\if{html}{\out{<a id="method-C_Value-clone"></a>}}
\if{latex}{\out{\hypertarget{method-C_Value-clone}{}}}
\subsection{Method \code{clone()}}{
The objects of this class are cloneable with this method.
\subsection{Usage}{
\if{html}{\out{<div class="r">}}\preformatted{C_Value$clone(deep = FALSE)}\if{html}{\out{</div>}}
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
