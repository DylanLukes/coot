
#ifdef MAKE_ENTERPRISE_TOOLS

#ifndef COD_TYPES_HH
#define COD_TYPES_HH

#include <string>
#include "use-rdkit.hh"

namespace cod {

   // can throw a std::runtime_error
   //
   // return a vector with as many items as there are atoms in rdkit_mol.
   // (throw an error if it can't do so).
   //
   // rdkit_mol is not const because there is no const beginAtoms() operator.
   std::vector<std::string> get_cod_atom_types(RDKit::ROMol &rdkit_mol);
   
   // can throw a std::runtime_error
   std::string get_cod_atom_type(RDKit::Atom *atom_base_p, // the parent of atom_p (if any)
				 RDKit::Atom *atom_p,
				 const RDKit::ROMol &rdkit_mol,
				 int level = 2);

   std::string make_cod_type(const std::string &atom_ele,
			     const std::vector<std::string> &neighbour_types,
			     int level);

   std::vector<std::string> sort_neighbours(const std::vector<std::string> &neighbours_in,
					    int level);
   bool neighbour_sorter(const std::string &a, const std::string &b);

} 

#endif // COD_TYPES_HH

#endif // MAKE_ENTERPRISE_TOOLS