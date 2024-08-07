% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/C_Behavior.R
\name{C_Behavior}
\alias{C_Behavior}
\title{A CHSM Behavior}
\description{
An R6 class mapping to a C++ composite Hierarchy State Machine object

  Implementation is provided by C++ objects.
}
\section{Super class}{
\code{\link[rchsm:C_Object]{rchsm::C_Object}} -> \code{C_Behavior}
}
\section{Methods}{
\subsection{Public methods}{
\itemize{
\item \href{#method-C_Behavior-new}{\code{C_Behavior$new()}}
\item \href{#method-C_Behavior-createVariables}{\code{C_Behavior$createVariables()}}
\item \href{#method-C_Behavior-clone}{\code{C_Behavior$clone()}}
}
}
\if{html}{\out{
<details open><summary>Inherited methods</summary>
<ul>
<li><span class="pkg-link" data-pkg="rchsm" data-topic="C_Object" data-id="finalize"><a href='../../rchsm/html/C_Object.html#method-C_Object-finalize'><code>rchsm::C_Object$finalize()</code></a></span></li>
</ul>
</details>
}}
\if{html}{\out{<hr>}}
\if{html}{\out{<a id="method-C_Behavior-new"></a>}}
\if{latex}{\out{\hypertarget{method-C_Behavior-new}{}}}
\subsection{Method \code{new()}}{
Constructs an object that is a new instance of the class
\subsection{Usage}{
\if{html}{\out{<div class="r">}}\preformatted{C_Behavior$new(className)}\if{html}{\out{</div>}}
}

\subsection{Arguments}{
\if{html}{\out{<div class="arguments">}}
\describe{
\item{\code{className}}{The name of the associated C class}
}
\if{html}{\out{</div>}}
}
}
\if{html}{\out{<hr>}}
\if{html}{\out{<a id="method-C_Behavior-createVariables"></a>}}
\if{latex}{\out{\hypertarget{method-C_Behavior-createVariables}{}}}
\subsection{Method \code{createVariables()}}{
Create the variables controlling the behavior in the provided holon
\subsection{Usage}{
\if{html}{\out{<div class="r">}}\preformatted{C_Behavior$createVariables(.machine, .holon)}\if{html}{\out{</div>}}
}

\subsection{Arguments}{
\if{html}{\out{<div class="arguments">}}
\describe{
\item{\code{.machine}}{The machine object where the variables should be registered}

\item{\code{.holon}}{The holon object where the variables should be created}
}
\if{html}{\out{</div>}}
}
}
\if{html}{\out{<hr>}}
\if{html}{\out{<a id="method-C_Behavior-clone"></a>}}
\if{latex}{\out{\hypertarget{method-C_Behavior-clone}{}}}
\subsection{Method \code{clone()}}{
The objects of this class are cloneable with this method.
\subsection{Usage}{
\if{html}{\out{<div class="r">}}\preformatted{C_Behavior$clone(deep = FALSE)}\if{html}{\out{</div>}}
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
