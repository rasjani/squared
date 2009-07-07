QMAKE_EXTRA_TARGETS+=astyle
contains(TEMPLATE,subdirs) {
    astyle.CONFIG=recursive
    astyle.target=astyle
    astyle.depends=FORCE
} else {
    astyle.target=astyle
    astyle.depends=FORCE
    astyle.commands=astyle 
    astyle.commands+= --indent=spaces=4
    astyle.commands+= --brackets=attach
    astyle.commands+= --indent-classes
    astyle.commands+= --indent-switches
    astyle.commands+= --indent-namespaces
    astyle.commands+= --indent-labels
    astyle.commands+= --max-instatement-indent=40
    astyle.commands+= --break-blocks
    astyle.commands+= --one-line=keep-blocks
    astyle.commands+= --one-line=keep-statements
    astyle.commands+= --preserve-date
    astyle.commands+= --quiet
    astyle.commands+= --suffix=none
    astyle.commands+= $$HEADERS $$SOURCES
}
