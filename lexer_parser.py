import lark
from lark import Lark
from lark.indenter import Indenter

from lark.tree import Tree
from lark import Token

from lark.reconstruct import Reconstructor


### hot patch lark tree and token repr
def Tree__repr__(self):
        return 'Tree(%r, %r)' % (self.data, self.children)
Tree.__repr__ = Tree__repr__

def Token__repr__(self):
        return 'Token(%r, %r)' % (self.type, self.value)
Token.__repr__ = Token__repr__
### hot patch lark tree and token repr

_parser = Lark.open('levir_syntax.lark',
    #parser='earley',
    rel_to=__file__,
    #ambiguity='resolve'
    lexer='standard'
    )

def parse_str(string):
    global _parser
    return _parser.parse(string)

def parse_file(name: str):
    with open(name) as file:
        print(
            parse_str(file.read())
                .pretty()
        )

if __name__ == '__main__':
    import sys
    print(sys.argv)
    parse_file(sys.argv[1])
