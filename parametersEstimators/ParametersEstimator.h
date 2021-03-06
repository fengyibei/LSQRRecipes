#ifndef _PARAMETERS_ESTIMATOR_H_
#define _PARAMETERS_ESTIMATOR_H_

#include "copyright.h"

#include <vector>

/**
 * This class defines the interface for parameter estimators.
 * Classes which inherit from it can be used by the Ransac class to perform robust
 * parameter estimation.
 * The interface includes three methods:
 * 1.estimate() - Estimation of the parameters using the minimal amount of data 
 *                (exact estimate).
 * 2.leastSquaresEstimate() - Estimation of the parameters using overdetermined 
 *                            data, so that the estimate minimizes a least squares 
 *                            error criterion.
 * 3.agree() - Does the given data agree with the model parameters.
 *
 * @author: Ziv Yaniv
 *
 */

namespace lsqrRecipes {

template<class T, class S>
class ParametersEstimator {
public:	

	/**
	 * Constructor which takes the number of data objects required for an exact 
	 * estimate (e.g. 2 for a line where the data objects are points)
	 */
	ParametersEstimator(unsigned int minElements) {this->minForEstimate = minElements;} 

	/**
	 * Exact estimation of parameters.
	 * @param data The data used for the estimate.
	 * @param parameters This vector is cleared and then filled with the computed parameters.
	 */
	virtual void estimate(std::vector<T *> &data, std::vector<S> &parameters) = 0;
	virtual void estimate(std::vector<T> &data, std::vector<S> &parameters) = 0;

	/**
	 * Least squares estimation of parameters.
	 * @param data The data used for the estimate.
	 * @param parameters This vector is cleared and then filled with the computed parameters.
	 */
	virtual void leastSquaresEstimate(std::vector<T *> &data, std::vector<S> &parameters) = 0;
	virtual void leastSquaresEstimate(std::vector<T> &data, std::vector<S> &parameters) = 0;

	/**
	 * This method tests if the given data agrees with the given model parameters.
	 */
	virtual bool agree(std::vector<S> &parameters, T &data) = 0;

	/**
	 * Returns the number of data objects required for an exact 
	 * estimate (e.g. 2 for a line where the data objects are points)
	 */
	unsigned int numForEstimate() {return this->minForEstimate;}
protected:
	unsigned int minForEstimate;
};

} //namespace lsqrRecipes

#endif //_PARAMETERS_ESTIMATOR_H_
