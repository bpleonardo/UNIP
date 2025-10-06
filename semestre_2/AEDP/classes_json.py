import json
from typing import Optional
from abc import abstractmethod


class DomainPart:
    def __init__(self, name: str, parent: Optional['DomainPart'] = None):
        self.name = name
        self.parent = parent
        self.parts = (name,)

    @classmethod
    def from_str(cls, domain: str):
        parts = domain.split('.')
        tld = None
        domain = None
        subdomains = []
        for i, name in enumerate(reversed(parts)):
            if i == 0:
                tld = TLD(name)
            elif i == 1:
                domain = Domain(name, tld)
            else:
                subdomains.append(Domain(name, subdomains[-1] if subdomains else domain))

        if subdomains:
            return subdomains[-1]
        return domain

    @property
    def fqdn(self):
        return '.'.join(self.parts)


    def to_dict(self):
        return {'name': self.name, 'fqdn': self.fqdn, 'parent': self.parent.to_dict() if self.parent else None}

    def save(self, filename: str):
        with open(filename, 'w') as f:
            json.dump(self.to_dict(), f, indent=2)


class RootZone(DomainPart):
    def __init__(self):
        super().__init__('.')
        self.parts = ()

class TLD(DomainPart):
    def __init__(self, name: str):
        super().__init__(name, RootZone())
        self.parts = (name,)

class Domain(DomainPart):
    def __init__(self, name: str, parent: DomainPart):
        super().__init__(name, parent)
        self.parts = (name, *parent.parts)


def main():
    domain = Domain.from_str('teste.sub.example.com')
    domain.save('teste.json')

if __name__ == '__main__':
    main()
